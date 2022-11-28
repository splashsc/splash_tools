int __fastcall get_sn(int fd, int level, int optname, void *optval, socklen_t *optlen)
{
  MEMORY[0](fd, level, optname, optval);
  return dns_acc_del();
}
// 4CE5D0: using guessed type int dns_acc_del(void);

