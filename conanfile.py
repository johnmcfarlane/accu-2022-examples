from conans import ConanFile, CMake


class PidConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/[2.x]", "fmt/[8.x]"
    generators = "cmake_find_package"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()
        cmake.install()
