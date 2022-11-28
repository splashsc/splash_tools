void __fastcall format_hi_history_data(_DWORD *a1, int a2, char *a3, int a4)
{
  int v5; // $v0

  if ( a2 > 0 )
  {
    v5 = J_atoi(*a1);
    snprintf(a3, a4, "%lu,", v5);
  }
}
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

