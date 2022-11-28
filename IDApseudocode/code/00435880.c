int __fastcall sub_435880(__pid_t a1, int *a2)
{
  __pid_t v3; // $v0
  bool v4; // dc
  int result; // $v0
  int v6; // [sp+18h] [-8h] BYREF

  *a2 = 0;
  v6 = 0;
  v3 = waitpid(a1, &v6, 1);
  if ( !v3 )
    return 0;
  v4 = v3 < 0;
  result = -1;
  if ( !v4 )
  {
    if ( (v6 & 0x7F) != 0 )
    {
      result = -1;
    }
    else
    {
      *a2 = (v6 & 0xFF00) >> 8;
      result = 1;
    }
  }
  return result;
}

