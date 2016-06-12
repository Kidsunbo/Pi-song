import datetime
import re

# Create a generator to yield 8 number of pi with a space in the center once
def pop_8_pi(precision = 10000):
    # Get pi with the precision of precision
    w = precision + 10
    b = 10 ** w
    x1 = b*4//5
    x2 = b // -239
    he = x1 + x2
    n = precision
    n *= 2
    for i in range(3, n, 2):
        x1 //= -25
        x2 //= -57121
        x = (x1+x2)//i
        he += x
    pi = he*4
    pi //= 10**10

    pi_s = str(pi)
    pi_s = pi_s[0]+"."+pi_s[1:]
    for i in range(0,len(pi_s),8):
        result = pi_s[i:i+8]
        result = result[:4]+" "+result[4:]
        yield result


def create_the_lrc():
    f = open("圆周率之歌.lrc", 'w')
    
    # Time part
    t = datetime.timedelta(0, 0)
    timediff = 3.2075
    for num_part in pop_8_pi(20000):
        t = t + datetime.timedelta(0, timediff)
        t_s = str(t)
        # Change the precision of the millisecond
        if "." in t_s:
            t_s = t_s[:-4]
        else:
            t_s += ".00"

        # Convert hour to minutes
        m = re.findall(r"\d{1,2}",t_s)
        minute = m[1]
        if m[0] == "0":
            pass
        else:
            minute = str(int(m[1])+int(m[0])*60)
        if int(minute) >= 68 and int(m[2]) > 25:
            break
        time_part = "["+minute+":"+m[2]+"."+m[3]+"]"
        f.write(time_part+num_part+"\n")
    f.close()
    print("Done")

if __name__ == "__main__":
    create_the_lrc()