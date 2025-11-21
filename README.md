# TestMPV
Use libmpv to play videos in the Qt environment, adding watermark functionality and screenshot functionality.The next step is to add Skia rendering.The subsequent step is to integrate OBS capture and save content as videos.This will form a complete video toolchain from capture and rendering to playback.

code:https://github.com/mpv-player/mpv-examples
libmpv  release: https://github.com/shinchiro/mpv-winbuild-cmake/releases/, download mpv-dev-x86_64xxx.7z.

msys mingw64：
gendef libmpv-2.dll

x64 Native Tools Command Prompt for VS：
lib /def:libmpv-2.def /out:libmpv-2.lib /machine:x64

can get libmpv-2.lib.
