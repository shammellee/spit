# spit
store and retrieve paths/commands/strings from the command line

# dependencies
* [Boost libraries][boost]

# building spit
* `$ export BOOST_ROOT=<boostPath>`
* `$ make`

# todo
* add entries `spit -a <key>:<string> ...`
* get path count `spit --length,#`
* list paths `spit [--list,ls]`
* remove entries by key `spit -d <key> ...`
* get entries by key `spit <key>`
* clear entries `spit -c`
* specify spitfile `spit --spitfile,-f <file>`
* silent `spit --silent,-s
* verbose `spit --verbose,-v`

[boost]: http://www.boost.org/