void srand(unsigned int seed)
{
  MEMORY[0](seed);
  cgi_signal_to_kernel();
}
// 4CCFE0: using guessed type int cgi_signal_to_kernel(void);

