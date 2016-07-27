# AIBot
AI Bot Written in Node and C++

## TODO

* Integrate node Object

## Debugging

If using Windows you can use visual studio otherwise for macs use the LLDB command line tool described below.

First, you need to do a debug build of your module.

`node-gyp build --debug`

Then `cd` to your project’s root. We need to know the absolute path to the node executable. Run:

`which node`

That will return the path to node.js. Now, run:

`lldb -- your/path/to/node {somefile.js}`

Adding breakpoints

`breakpoint set -f {somefile.cpp} -l 25`

Then start

`run`



