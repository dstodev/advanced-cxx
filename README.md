# Sample Eigen project

This project serves as an opinionated template project which includes:
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) \([repo](https://gitlab.com/libeigen/eigen)\)
- [GoogleTest](https://github.com/google/googletest)
- [Google Benchmark](https://github.com/google/benchmark)

## Build dependencies

- [CMake 3.14+](https://cmake.org/)
- [Conan](https://conan.io/)
- [Docker Desktop](https://www.docker.com/products/docker-desktop) (to run Docker tests)

## Running tests

The following scripts have been tested on MacOS Monterey and Windows 10.

- Natively
  - on Mac, Linux, or Windows with WSL  
    Run `script/run-tests.sh`

- through Docker
  - on Mac/Linux  
    Run `script/run-docker-tests.sh`

  - on Windows  
    Run `script/run-docker-tests.bat`  

# Visual Studio Code integration

Open the project as a workspace using `project.code-workspace`.

Installing the extensions identified in `.vscode/extensions.json` will include, among other helpful
tools, the `ms-vscode.cmake-tools` extension. CMake Tools integrates CMake into VS Code to provide
code intellisense and other helpful build utilities.

Notes:  
- Make sure that the CMake Tools extension is configured to match the CMAKE_BUILD_TYPE.
- There are currently intellisense bugs on MacOS due to CMake Tools. One such issue is being tracked
  [here](https://github.com/microsoft/vscode-cmake-tools/issues/1178).
