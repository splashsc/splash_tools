void __fastcall __noreturn sub_42C3EC(int a1)
{
  dword_67D0C4 = 1;
  if ( dword_667724 != -1 )
  {
    close_socket(dword_667724);
    dword_667724 = -1;
  }
  if ( dword_667720 != -1 )
  {
    close_socket(dword_667720);
    dword_667720 = -1;
  }
  if ( https_fd != -1 )
    close_socket(https_fd);
  https_ssl_uninit(0);
  printf("\n SignalFunc_SEGV %d\n", a1);
  exit(0);
}
// 667720: using guessed type int dword_667720;
// 667724: using guessed type int dword_667724;
// 67BD44: using guessed type int https_fd;
// 67D0C4: using guessed type int dword_67D0C4;

