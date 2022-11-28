void __fastcall ai_ping_check_file_status(const char *a1, int a2, _DWORD *a3)
{
  char *v3; // $v0

  if ( a1 )
  {
    v3 = strstr(a1, "packets received, ");
    if ( v3 )
    {
      if ( J_atoi(v3 + 18) != 100 )
        *a3 = 1;
    }
  }
}
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

