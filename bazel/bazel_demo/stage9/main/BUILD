cc_binary(
    name = "hello-world",
    #srcs = glob(["*.cc","*.h"]),
    srcs = ["hello-world.cc", "hello-local.cc","hello-local.h"],
    deps = [
        "@lib_first//hello_time:hello-time",
        "@lib_static//static1.0:hello-echo",
        "@com_google_googletest//:gtest_main",
    ],
    copts = [
        "-std=c++11",
    ],
    linkopts = [
        "-lpthread",
        "-ldl",
    ],
)

cc_library(
    name = "hello-world-lib",
    #srcs = glob(["*.cc","*.h"]),
    srcs = ["hello-world.cc", "hello-local.cc","hello-local.h"],
    deps = [
        "@lib_first//hello_time:hello-time",
        "@lib_static//static1.0:hello-echo",
        "@com_google_googletest//:gtest_main",
    ],
    copts = [
        "-std=c++11",
    ],
    linkopts = [
        "-lpthread",
        "-ldl",
    ],
)

cc_test(
    name = "local_test",
    srcs = ["hello-local_test.cc"],
    visibility = ["//visibility:private"],
    deps = [
        ":hello-world-lib",
        "@com_google_googletest//:gtest_main",
    ],
)
