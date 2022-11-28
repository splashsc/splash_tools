__pid_t __fastcall wait_any_nohang(int *a1)
{
  return safe_waitpid(-1, a1, 1);
}

