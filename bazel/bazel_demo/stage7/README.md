# Stage 7

In this stage we step it up and showcase how to generated protobuf files to be used by gRPC.

helloworld.pb.{h,cc}文件的生成是由cc_proto_library规则生成，在protobuf中有定义。

helloworld.grpc.pb.{h,cc}由cc_grpc_library规则生成，在grpc/bazel/cc_grpc_library.bzl中有定义。

WORKSPACE中包含有protobuf和grpc的一些声明，详见代码。具体生成规则如BUILD文件中所描述：

```python
proto_library(
    name = "helloworld_proto",
    srcs = [":helloworld.proto"],
)

cc_proto_library(
    name = "helloworld_cc_proto",
    deps = [":helloworld_proto"],
)

cc_grpc_library(
    name = "helloworld_cc_grpc",
    srcs = [":helloworld_proto"],
    grpc_only = True,
    deps = [":helloworld_cc_proto"],
)
```

使用`bazel build //protos:helloworld_cc_grpc`命令，生成的文件如下：

```
➜  stage7 git:(master) ✗ tree bazel-bin/protos
bazel-bin/protos
├── helloworld.grpc.pb.cc
├── helloworld.grpc.pb.h
├── helloworld.pb.cc
├── helloworld.pb.h
├── libhelloworld_cc_grpc.a
└── libhelloworld_cc_grpc.so
```

