# spit
store and retrieve paths/strings from the command line

# todo
* get path count `spit --length,#`
* list paths `spit [--list]`
* add strings `spit +<key>:<string> ...`
* remove strings by key `spit [--delete <key> ...,-<key> ...]`
* get string by key `spit <key>`
* clear strings `spit x`
* specify spitfile `spit --spitfile,-f <file>`
* help `spit --help,-h`

# .spitfile
* single path per line
	~/Desktop
	/etc/hosts
	/Volumes/Storage/media/p
	somelongcommand --with-a-lot of --complex flags