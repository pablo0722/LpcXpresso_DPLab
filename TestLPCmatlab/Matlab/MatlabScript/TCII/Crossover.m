% orden 1
num = [ 1];
den = [ 1 1];
H1LP = tf(num,den);

num = [1 0 ];
den = [1 1];
H1HP = tf(num,den);


% orden 2 
num = [ 1];
den = [ 1 2^0.5 1];
H2LP = tf(num,den);

num = [1 0 0];
den = [1 2^0.5 1];
H2HP = tf(num,den);


bode(H1LP,H1HP,H2LP,H2HP);