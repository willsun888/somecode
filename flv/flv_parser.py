#!/usr/bin/python3

from enum import Enum
import bitstruct

class TagType(Enum):
    AUDIO = 0x8
    VIDEO = 0x9
    SCRIPT_DATA = 0x12

class ScriptDataType(Enum):
    DOUBLE = 0
    UI8 = 1
    SCRIPTDATASTRING = 2
    SCRIPTDATAOBJECT = 3
    UI16 = 7
    SCRIPTDATAECMAARRAY = 8
    SCRIPTDATAOBJECTPROPERTY = 10
    SCRIPTDATADATE = 11
    SCRIPTDATALONGSTRING = 12

class FLVHeader:
    def __init__(self, file):
        self.file = file

    def decode(self):
        header = bitstruct.unpack("t24u8u5u1u1u1u32", self.file.read(3+1+1+4))
        self.signature = header[0]
        self.version = header[1]
        self.type_flags_reserved1 = header[2]
        self.type_flags_audio = header[3]
        self.type_flags_reserved2 = header[4]
        self.type_flags_video = header[5]
        self.data_offset = header[6]

    def str(self):
        return "FLVHeader, signature:{0}, version:{1}, type_flags_audio:{2}, type_flags_video:{3}, data_offset:{4}".format(
            self.signature,
            self.version,
            self.type_flags_audio,
            self.type_flags_video,
            self.data_offset
        )

class TAGHeader:
    def __init__(self, file):
        self.file = file

    def decode(self):
        tag = bitstruct.unpack("u32u2u1u5u24u24u8u24", self.file.read(4+1+3+3+1+3))
        self.pre_tag_size = tag[0]
        self.reserved = tag[1]
        self.filter = tag[2]
        self.tag_type = tag[3]
        self.data_size = tag[4]
        self.timestamp = tag[5]
        self.timestamp_extended = tag[6]
        self.stream_id = tag[7]
        if self.tag_type == TagType.SCRIPT_DATA.value:
            script_tag = ScriptDataTAG(f)
            print(script_tag.str())

    def str(self):
        return "TAGHeader, pre_tag_size:{0}, reserved:{1}, filter:{2}, tag_type:{3}, data_size:{4}, timestamp:{5}, timestamp_extended:{6}, stream_id:{7}".format(
        self.pre_tag_size,
        self.reserved,
        self.filter,
        self.tag_type,
        self.data_size,
        self.timestamp,
        self.timestamp_extended,
        self.stream_id
        )

class ScriptDataTAG:
    def __init__(self, file):
        self.file = file
        self.decode()

    def decode(self):
        tag = bitstruct.unpack("u8", self.file.read(1))
        self.type = tag[0]
        if self.type == ScriptDataType.SCRIPTDATASTRING.value:
            SCRIPTDATASTRING(self.file).print()
        elif self.type == ScriptDataType.SCRIPTDATAECMAARRAY.value:
            print("\t\tAMF1 type: SCRIPTDATAECMAARRAY")
            print("\t\tAMF1 metadata count: %d" % alen)
            print("\t\tMetadata:")

    def str(self):
        return "ScriptDataTAG, type:{0}".format(self.type)

class SCRIPTDATAVALUE:
    def __init__(self, file):
        self.file = file
    def str(self):
        self.vtype = bitstruct.unpack("u8", self.file.read(1))[0]

class SCRIPTDATASTRING:
    def __init__(self, file):
        self.file = file
        self.len = bitstruct.unpack("u16", self.file.read(2))[0]
        self.str = bitstruct.unpack("t"+str(self.len*8), self.file.read(self.len))[0]
    def print(self):
        print("\t\tAMF1 type: STRING")
        print("\t\tAMF1 string size: %d" % self.len)
        print("\t\tAMF1 string: %s" % self.str)

'''
SCRIPTDATADATE
Field               Type    Comment
DateTime            DOUBLE  Number of milliseconds since Jan 1, 1970 UTC.
LocalDateTimeOffset SI16    Local time offset in minutes from UTC
'''
class SCRIPTDATADATE:
    def __init__(self, file):
        self.file = file
    def decode(self):
        pass
'''
SCRIPTDATAECMAARRAY
Field               Type                        Comment
ECMAArrayLength     UI32                        Approximate number of items in ECMA array
Variables           SCRIPTDATAOBJECTPROPERTY[]  List of variable names and values
List Terminator     SCRIPTDATAOBJECTEND         List terminator
'''
class SCRIPTDATAECMAARRAY:
    def __init__(self, file):
        self.file = file
    def decode(self):
        self.len = bitstruct.unpack("u32", self.file.read(4))[0]
        self.variables = []
        for i in range(self.len):
            self.variables.append(SCRIPTDATAOBJECTPROPERTY(file))
        self.term = SCRIPTDATAOBJECTEND(file)
    def print(self):
        print("\t\tAMF1 type: SCRIPTDATAECMAARRAY")
        print("\t\tAMF1 metadata count: %d" % self.len)
        print("\t\tMetadata:")
'''
SCRIPTDATAOBJECTPROPERTY
Field           Type               Comment
PropertyName    SCRIPTDATASTRING   Name of the object property or variable
PropertyData    SCRIPTDATAVALUE    Value and type of the object property or variable
'''
class SCRIPTDATAOBJECTPROPERTY:
    def __init__(self, file):
        self.file = file
    def decode(self):
        klen = bitstruct.unpack("u16", self.file.read(2))[0]
        self.key = bitstruct.unpack("t"+str(klen*8), self.file.read(klen))[0]
        self.value = SCRIPTDATAVALUE(file)
    def print(self):
        pass
'''
SCRIPTDATAOBJECTEND
Field           Type    Comment
ObjectEndMarker UI8[3]  Shall be 0, 0, 9
'''
class SCRIPTDATAOBJECTEND:
    def __init__(self, file):
        self.file = file
    def decode(self):
        self.end_marker = bitstruct.unpack("u24", self.file.read(3))[0]
    def str(self):
        return "script_tag end"
    def print(self):
        pass

if __name__ == "__main__":
    f = open("demo.flv", "rb")
    flv = FLVHeader(f)
    flv.decode()
    print(flv.str())
    tag = TAGHeader(f)
    tag.decode()
    print(tag.str())
