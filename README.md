# Calling C from Python with C API.

Steps:

```bash
uv sync
uv build
uv pip install dist/hello-0.1.0-cp313-cp313-macosx_11_0_arm64.whl
# Remember hello-0.1.0-cp313-cp313-macosx_11_0_arm64.whl is for what I made, yours may be differant
uv run main.py
```
