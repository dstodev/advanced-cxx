# https://docs.conan.io/en/latest/mastering/conanfile_py.html
# 2022-09-16 requires `pip install conan --pre`
#                  or `pip install --upgrade conan --pre`
from conans import ConanFile


class Project(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    requires = ('gtest/1.11.0@',  # https://conan.io/center/gtest
                'benchmark/1.6.0@',  # https://conan.io/center/benchmark
                'eigen/3.4.0@',  # https://conan.io/center/eigen
                'qt/6.3.1@')  # https://conan.io/center/qt
    # TODO: something with MQTT
    generators = 'cmake_find_package',
    default_options = {'qt:shared': True}

    def imports(self):
        self.copy('*.dll', src='bin', dst='../bin')  # put dll files in INSTALL_FOLDER/../bin (project bin dir)
        self.copy('*.dylib', src='lib', dst='../bin')
