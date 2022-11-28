int __fastcall httpd_proxy_check(int a1, _DWORD *a2)
{
  const void *v2; // $s1
  bool v4; // dc
  int result; // $v0

  v2 = *(const void **)(a1 + 44);
  *a2 = 0;
  v4 = memcmp(v2, "/ac/", 4u) == 0;
  result = 1;
  if ( v4 )
    goto LABEL_4;
  if ( !memcmp(v2, "/rt/", 4u) )
    goto LABEL_3;
  v4 = memcmp(v2, "/ap/", 4u) == 0;
  result = 1;
  if ( v4 )
    goto LABEL_4;
  v4 = memcmp(v2, "/acs/", 5u) == 0;
  result = 0;
  if ( v4 )
  {
LABEL_3:
    result = 1;
LABEL_4:
    *a2 = 1;
  }
  return result;
}

