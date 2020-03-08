# Stage 6

In this stage we showcase how to use .bzl file.

```
stage6
├── BUILD
├── README.md
├── WORKSPACE
├── deps.bzl
└── main
    ├── BUILD
    └── hello-world.cc
```

Stage 6中为了使用.bzl文件，将Stage 5中WORKSPACE的依赖提取了出来，所以WORKSPACE的内容将会很简化：

```python
load("//:deps.bzl", "load_deps")

load_deps()
```

.bzl中将http_archive封装到函数中：

```python
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_deps():
    if "com_google_absl" not in native.existing_rules():
        http_archive(
            name = "com_google_absl",
						...
...
```