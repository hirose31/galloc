# galloc - Gachapin alloc

## ABOUT

Gachapin and Mukku reports on malloc and free.

## HOWTO

```
$ make galloc.so
$ LD_PRELOAD=./galloc.so ls # or arbitrary command

Gachapin .oO(malloc(568) = 0x172e040)
Gachapin .oO(malloc(120) = 0x172e280)
Mukku    .oO(free = 0x172e040)
Gachapin .oO(malloc(6) = 0x172e040)
Mukku    .oO(free = 0x172e040)
...
```

## SEE ALSO

* http://en.wikipedia.org/wiki/Gachapin
* http://togetter.com/li/574262
* http://www.youtube.com/watch?v=0-vWT-t0UHg

