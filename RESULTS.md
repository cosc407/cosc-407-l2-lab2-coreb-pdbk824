# Lab 2 results — sealed core

Name:  Porter de Bosch Kemper
Student number:  82479502
Lab section:  L2
Core:  b
Machine:  Codespace
Cores:  4

## Tools and sources

Tools and sources: Lecture slides

> Mandatory, even if it says "none". **No AI in the lab, at all** — see the
> README. Missing declaration: zero until you supply one. False one: misconduct.

## S2 — the defect · 40 marks

Three or more runs of `./bar given`, including one thread:

`mode=given threads=1 rounds=10000 bad=0 firstbad=-1 checksum=ok correct=yes deadlock=no time=0.0093 cpu=0.0094`
`mode=given threads=2 rounds=10000 bad=0 firstbad=-1 checksum=ok correct=yes deadlock=no time=0.2245 cpu=0.1918`
`mode=given threads=3 rounds=10000 bad=-1 firstbad=-1 checksum=unknown correct=no deadlock=yes time=5.0089 cpu=0.0025`

**S2.1** Name the mechanism: which claim in `given.c`'s header is false, and
what is actually happening? State the barrier's invariant and say which half of
it this code does not keep.

Every thread waiting on that condition
 variable is waiting for the same thing and the generation has already
 changed before the signal goes out, so all of them are released

**S2.2** Prove it, in the form your `BRIEF.md` requires.

It works with only two threads because signal awakes a thread and since there only is one other thread waiting it works, breaks at three since a thread is left waiting. 
**S2.3** Minimality: what breaks if you do less, what it costs if you do more.

The invariant is the number of threads it waits for, and it would have to itterate over every threads waking them individually

## S3 — the measurement · 30 marks

`./bar all <t> <rounds>` at 1, 2, 4 and 8 threads. Pasted, not retyped. If a
mode stops, `all` stops with it — run the modes one at a time and paste those.

mode=given threads=1 rounds=1000 bad=0 firstbad=-1 checksum=ok correct=yes deadlock=no time=0.0009 cpu=0.0009
mode=fixed threads=1 rounds=1000 bad=0 firstbad=-1 checksum=ok correct=yes deadlock=no time=0.0010 cpu=0.0011
mode=alt threads=1 rounds=1000 bad=-1 firstbad=-1 checksum=unknown correct=no deadlock=yes time=5.0090 cpu=0.0020
alt: no progress after 5.0 s -- giving up. This is a result, not a crash: paste the line above.

mode=given threads=2 rounds=1000 bad=0 firstbad=-1 checksum=ok correct=yes deadlock=no time=0.0209 cpu=0.0209
mode=fixed threads=2 rounds=1000 bad=0 firstbad=-1 checksum=ok correct=yes deadlock=no time=0.0221 cpu=0.0205
mode=alt threads=2 rounds=1000 bad=-1 firstbad=-1 checksum=unknown correct=no deadlock=yes time=5.0077 cpu=0.0017
alt: no progress after 5.0 s -- giving up. This is a result, not a crash: paste the line above.

mode=given threads=4 rounds=1000 bad=-1 firstbad=-1 checksum=unknown correct=no deadlock=yes time=5.0084 cpu=0.0021
given: no progress after 5.0 s -- giving up. This is a result, not a crash: paste the line above.

mode=given threads=8 rounds=1000 bad=-1 firstbad=-1 checksum=unknown correct=no deadlock=yes time=5.0085 cpu=0.0024
given: no progress after 5.0 s -- giving up. This is a result, not a crash: paste the line above.

| threads | given: correct? | given: time | given: cpu | fixed: time | fixed: cpu | alt: time | alt: cpu |
|---|---|---|---|---|---|---|---|
| 1 | | | | | | | |
| 2 | | | | | | | |
| 4 | | | | | | | |
| 8 | | | | | | | |

**S3.1** Reconcile with `PREDICTION.md`: quote what you predicted, say what
happened, account for the difference. If you were right, say what would have
made you wrong.

Yes, it will be right because the barrier will not have to wait for another thread, single arrives > checks > goes

I was kind if correct, threads were being left waiting but not for the reason that i thought, I assumed that threads were just going whenever but in actuality they were just being released singularly

**S3.2** Which would you ship on this machine, **and what measurement would
change your mind?**

fixed since it works, maybe if alt was way faster
## S4 — explain-back · 15 marks

> Two or three sentences, your own words: someone who has not seen this code
> asks *what was wrong with it, and what did fixing it cost?*

Threads are being left waiting for something that will never come. Changing it was as simple as changing signal to broadcast. 
## Anything you got stuck on

I kept overlooking that it could be a wrong funciton and was focused on the mutexes