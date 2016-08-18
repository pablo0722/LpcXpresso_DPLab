function x = fi_m_radix2fft_algorithm1_6_2(x, w)
n = length(x);  t = log2(n);
x = fi_bitreverse(x,n);
for q=1:t
  L = 2^q; r = n/L; L2 = L/2;
  for k=0:(r-1)
    for j=0:(L2-1)
      temp          = w(L2-1+j+1) * x(k*L+j+L2+1);
      x(k*L+j+L2+1) = x(k*L+j+1)  - temp;
      x(k*L+j+1)    = x(k*L+j+1)  + temp;
    end
  end
end