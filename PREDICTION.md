# Prediction sheet — push by 0:20, before you compile

> Marked on **having predicted** and on reconciling it in S3.1 — **not on being
> right.** A confident wrong prediction you then explain is full marks. A blank
> page is none. A page timestamped after your first run is worse than none.
>
> Read `src/given.c` and `BRIEF.md`. Run nothing.

Cores:  4
Lab 0 spread:  13.6

> **P1.** `./bar given` on **one** thread — does it come out right? Yes/no, one
> sentence why.

Yes, it will be right because the barrier will not have to wait for another thread, single arrives > checks > goes

> **P2.** On **8** threads, pick one and commit to it: right answer / wrong
> answer / it stops. If wrong, roughly how big is `bad`? If it stops, say at
> which of the two waits in a round.

Wrong answer, on average will be small bad

> **P3.** Three runs at 8 threads — **identical** numbers, or different? Think
> about this one before you write it; it is the most useful line on the page.

I believe that it will be different numbers as the barrier does not ensure that a thread does not arrive late

> **P4.** Seconds, before measuring. Orders of magnitude are what matter. `cpu`
> is process CPU time over all threads, so `cpu`/`time` is how many cores were
> busy — one number per box.

| | 1 thread: time | 8 threads: time | 8 threads: cpu/time |
|---|---|---|---|
| `given` |0.5|0.8|3|
| `fixed` |0.4|0.7|2|
| `alt`   |0.3|1.1|2|

> **P5.** Fastest and slowest at 8 threads? Name anything you expect to get
> **slower** as threads are added, and anything you expect to stop altogether.

Fastest will hoefully be fixed where the slowest at 8 would be alt, I'd assume that once too many threads are added given would stop alltogether 
