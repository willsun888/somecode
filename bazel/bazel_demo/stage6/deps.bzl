load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def load_deps():
    if "com_google_absl" not in native.existing_rules():
        http_archive(
            name = "com_google_absl",
            sha256 = "84b4277a9b56f9a192952beca535313497826c6ff2e38b2cac7351a3ed2ae780",
            strip_prefix = "abseil-cpp-c476da141ca9cffc2137baf85872f0cae9ffa9ad",
            url = "https://github.com/abseil/abseil-cpp/archive/c476da141ca9cffc2137baf85872f0cae9ffa9ad.zip",
        )

    if "zlib" not in native.existing_rules():
        http_archive(
            name = "zlib",
            build_file_content = """
cc_library(
    name = "zlib",
    srcs = glob(["*.c", "*.h"]),
    includes = ["."],
    visibility = ["//visibility:public"],
)
            """,
            sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
            strip_prefix = "zlib-1.2.11",
            urls = ["https://mirror.bazel.build/zlib.net/zlib-1.2.11.tar.gz"],
        )
