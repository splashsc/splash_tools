int *__fastcall httpd_get_file(const char *a1, int a2)
{
  int *v2; // $s0
  bool v4; // dc
  int *result; // $v0

  v2 = (int *)gl_file_hash[a2];
  if ( !v2 )
    return 0;
  while ( 1 )
  {
    v4 = strcmp((const char *)v2[2], a1) != 0;
    result = v2;
    if ( !v4 )
      break;
    v2 = (int *)*v2;
    if ( !v2 )
      return 0;
  }
  return result;
}

