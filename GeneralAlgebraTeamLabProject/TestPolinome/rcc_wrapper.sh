#!/bin/bash
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/mplaksyuk/Qt/6.3.0/macos/libexec/rcc "$@"
