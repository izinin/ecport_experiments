# [c_port](https://www.erlang.org/doc/tutorial/c_port.html)

* activate Kerl :`. /home/izinin/kerl/installations/21.3.8.24/activate` 
* compile: `gcc -o extprg complex.c erl_comm.c port.c worker.c`
* Start Erlang and compile the Erlang code:

```erlang
unix> erl
Erlang (BEAM) emulator version 4.9.1.2

Eshell V4.9.1.2 (abort with ^G)
1> c(complex1).
{ok,complex1}
```

* Run the example:

```erlang
2> complex1:start("./extprg").
<0.34.0>
3> complex1:foo(3).
4
4> complex1:bar(5).
10
5> complex1:stop().
stop

T = erlang:ports().
erlang:port_info(lists:nth(4,T)).
erlang:port_close(lists:nth(4,T)).
```
