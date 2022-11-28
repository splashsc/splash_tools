int __fastcall sub_423418(int a1)
{
  int *v2; // $v0
  int v3; // $s1
  int v4; // $a1
  int *v5; // $v0
  int *v6; // $s1
  const char *v7; // $s0
  int result; // $v0
  int *v9; // $s2

  v3 = get_name_hash((unsigned __int8 *)(*(_DWORD *)(a1 + 44) + 1));
  v2 = httpd_find_ext_file((const char *)(*(_DWORD *)(a1 + 44) + 1), v3);
  v4 = v3;
  v6 = v2;
  v5 = httpd_get_file((const char *)(*(_DWORD *)(a1 + 44) + 1), v4);
  v7 = *(const char **)(a1 + 44);
  v9 = v5;
  result = strcmp(v7, "/relogin.htm");
  if ( result )
  {
    result = strcmp(v7, "/login.html");
    if ( result )
    {
      if ( !v6 || (result = 1, v6[4] >= 2) )
      {
        result = 0;
        if ( v9 )
          result = v9[3] < 2;
      }
    }
  }
  return result;
}

