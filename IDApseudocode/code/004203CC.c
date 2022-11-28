const char *__fastcall httpd_find_type2(const char *a1)
{
  char *v1; // $v0
  char *v3; // $s2
  char *v4; // $v0
  const char *v5; // $s1
  _DWORD *v6; // $s0
  char *v8; // $v0

  v1 = strchr(a1, 63);
  v3 = v1;
  if ( v1 )
  {
    *v1 = 0;
    v4 = strrchr(a1, 46);
    v5 = v4 + 1;
    if ( v4 )
    {
      v6 = (_DWORD *)file_type2_str_hash[get_name_hash((unsigned __int8 *)v4 + 1)];
      if ( v6 )
        goto LABEL_6;
      *v3 = 63;
      return "application/octet-stream";
    }
LABEL_11:
    *v3 = 63;
    return "application/octet-stream";
  }
  v8 = strrchr(a1, 46);
  v5 = v8 + 1;
  if ( v8 )
  {
    v6 = (_DWORD *)file_type2_str_hash[get_name_hash((unsigned __int8 *)v8 + 1)];
    if ( v6 )
    {
      do
      {
LABEL_6:
        if ( !strcmp((const char *)*(v6 - 2), v5) )
        {
          if ( v3 )
            *v3 = 63;
          return (const char *)*(v6 - 1);
        }
        v6 = (_DWORD *)*v6;
      }
      while ( v6 );
      if ( !v3 )
        return "application/octet-stream";
      goto LABEL_11;
    }
  }
  return "application/octet-stream";
}

