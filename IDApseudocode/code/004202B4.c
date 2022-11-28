char *httpd_find_type2_init()
{
  char *result; // $v0
  unsigned __int8 *v1; // $a0
  void **v2; // $s0
  void **v3; // $v1
  bool v4; // dc

  result = (char *)&file_type2_str_hash;
  do
  {
    *(_DWORD *)result = 0;
    result += 4;
  }
  while ( result != gl_httpd_high_adminpwd_md5 );
  v1 = (unsigned __int8 *)file_type2_str;
  v2 = (void **)&unk_66619C;
  if ( file_type2_str )
  {
    do
    {
      v3 = (void **)((char *)&file_type2_str_hash + 4 * get_name_hash(v1));
      result = (char *)*v3;
      v4 = *v3 == 0;
      *v2 = *v3;
      if ( !v4 )
        *((_DWORD *)result + 1) = v2;
      *v3 = v2;
      v2[1] = v3;
      v2 += 4;
      v1 = (unsigned __int8 *)*(v2 - 2);
    }
    while ( v1 );
  }
  return result;
}
// 666194: using guessed type char **file_type2_str;

