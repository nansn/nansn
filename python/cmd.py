#! /usr/bin/env python3
import subprocess
 
def test(size):
    print('start')
 
    cmd = 'dd if=/dev/urandom bs=1 count=%d 2>/dev/null' % size
    p = subprocess.Popen(args=cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, close_fds=True)
    #p.communicate()
    p.wait()  # 这里超出管道限制，将会卡住子进程
 
    print('end')
 
# 64KB
test(64 * 1024)
 
# 64KB + 1B
test(64 * 1024 + 1)


