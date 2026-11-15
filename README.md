# Calling C from Python with the Python/C API

Minimal example of writing a small C library and calling it from Python using **Python extension module in C**. There is another repository for [Python Ctypes](https://github.com/BlackIQ/python-ctypes) that you can check them out.

Unlike `ctypes`, which loads an existing shared library and calls its functions, the Python/C API lets us write C code that is exposed to Python as an importable module.

This repository is just a personal learning note.

## How Does It Work?

We include `Python.h` and implement the functions that we want to expose to Python.

We then define a method table and a module definition, and provide a module initialization function. Python calls that initialization function when the compiled extension is imported.

In this example, the C extension provides a module named `hello` with a `greet()` function.

## Requirements

- Python
- UV
- Make

## Setup

Clone the repository and navigate to its directory. After that go on next steps.

### Install Dependencies

Sync the project environment:

```bash
uv sync
```

### Build the project

You should build the project to get the shared lib file `.so` and then to use it.

```bash
uv build
```

### Verify the build

So, you synced, built and now you need to use it. Check out `dist` dir and you might see something like this:

```bash
hello-0.1.0-cp313-cp313-macosx_11_0_arm64.whl
```

That is the file you need to add. Remember this file name can be changed based on your system and other things.

### Install

Last step of the setup is installing it:

```bash
uv pip install path/to/hello-0.1.0-cp313-cp313-macosx_11_0_arm64.whl
```

All done!

## Run

Run the example:

```bash
uv run main.py
```

Expected output:

```text
Hello, Amirhossein!
```

## Notes

- The extension is implemented in C using the Python/C API.
- The module is imported from Python with `import hello`.
- The extension exposes a `greet()` function.
- The project uses setuptools as its build backend and uv to manage the environment and run build commands.
- This is a native CPython extension, not a shared library loaded manually with `ctypes`.
