__pid_t __fastcall safe_waitpid(__pid_t a1, int *a2, int a3)
{
  __pid_t v6; // $s0

  do
    v6 = waitpid(a1, a2, a3);
  while ( v6 == -1 && *_errno_location() == 4 );
  return v6;
}

