# The cc_proto_library rule generates C++ code for a proto_library rule. It
# must have exactly one proto_library dependency. If you want to use multiple
# proto_library targets, create a separate cc_proto_library target for each
# of them.
#
# Remote repository "com_google_protobuf_cc" must be defined to use this rule.

load("@com_google_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

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
    visibility = ["//visibility:public"],
    deps = [":helloworld_cc_proto"],
)
