char *__fastcall sub_420900(int a1, char *a2)
{
  char *v3; // $v0
  int v5; // $a0
  int v6; // $v0
  char *v7; // $s0
  char *result; // $v0

  v3 = httpd_get_parm(a1, a2);
  v5 = a1;
  v7 = v3;
  v6 = httpd_get_json_parm(v5, (int)a2);
  if ( v7 || !v6 )
    result = v7;
  else
    result = *(char **)(v6 + 16);
  return result;
}

