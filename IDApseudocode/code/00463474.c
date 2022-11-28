int __fastcall check_ips_group_contain(const char *a1, const char *a2)
{
  char *v4; // $v0
  int v5; // $v0
  int result; // $v0

  v4 = strchr(a2, 62);
  if ( !v4 || (*v4 = 0, v5 = J_atoi(v4 + 1), v5 == 1) || v5 == 4 )
    result = 0;
  else
    result = sub_4633B0(a1, (int)a2);
  return result;
}
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

