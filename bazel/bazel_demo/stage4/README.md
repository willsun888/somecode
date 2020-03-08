# Stage 4

Stage4中分别将stage3中的两个依赖分别独立成两个独立的项目，hello-greet为non-Bazel项目，hello-time为Bazel项目。目录结构如下：

```
hello-greet-lib
└── some_lib
    ├── hello-greet.cc
    └── hello-greet.h
```

```
hello-time-lib
├── README.md
├── WORKSPACE
└── lib
    ├── BUILD
    ├── hello-time.cc
    └── hello-time.h
```

WORKSPACE文件

```
new_local_repository(
    name = "hello_greet_lib",
    build_file = "//:greet.BUILD",
    path = "../hello-greet-lib/some_lib",
)

local_repository(
    name = "hello_time_lib",
    path = "../hello-time-lib",
)
```

可以看到non-Bazel的项目需要使用`new_`开头的命令，并且需指定`build_file`或者`build_file_content`。

碰到了一个错误，说build_file不存在，因为根目录没有创建BUILD文件，在项目目录touch一个空BUILD文件可解决。

```
ERROR: /repos/stage4/main/BUILD:1:1: no such package '@hello_greet_lib//': Unable to load package for @//:greet.BUILD: not found. and referenced by '//main:hello-world'
ERROR: Analysis of target '//main:hello-world' failed; build aborted: Analysis failed
```