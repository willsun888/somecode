#coding=utf-8

from  BaseHTTPServer import HTTPServer,BaseHTTPRequestHandler
import urllib
import json
 
class ServerHTTP(BaseHTTPRequestHandler):
    def do_GET(self):
        path = self.path
        query = urllib.splitquery(path)
        print query
        self.send_response(200)
        self.send_header("Content-type","text/html")
        self.end_headers()
        obj = {"spam" : "foo", "parrot" : 42}
        data = json.dumps(obj)
        self.wfile.write(data)
        
    def do_POST(self):
        path = self.path
        print path
        #获取post提交的数据
        datas = self.rfile.read(int(self.headers['content-length']))
        datas = urllib.unquote(datas).decode("utf-8", 'ignore')
        
        self.send_response(200)
        self.send_header("Content-type","text/html")
        self.send_header("test","This is test!")
        self.end_headers()
        buf = '''<!DOCTYPE HTML>
        <html>
            <head><title>Post page</title></head>
            <body>Post Data:%s  <br />Path:%s</body>
        </html>'''%(datas,self.path)
        self.wfile.write(buf)

class Processor
    def init(conf):
        print conf;

    def process():
        print "process";

    def get

def start_server(port):
    http_server = HTTPServer(('', int(port)), ServerHTTP)
    http_server.serve_forever() 
    
if __name__ == "__main__":
    init();
    start_server(8000)
