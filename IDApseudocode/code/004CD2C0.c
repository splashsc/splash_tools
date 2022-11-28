int listen(int fd, int n)
{
  MEMORY[0](fd, n);
  return set_xwgl_ref_to_kernel();
}
// 4CD2D0: using guessed type int set_xwgl_ref_to_kernel(void);

