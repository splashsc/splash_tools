char *__fastcall httpd_find_ext_name(const char *a1)
{
  char *v1; // $v0
  char *result; // $v0

  v1 = strchr(a1, 63);
  if ( v1 )
    *v1 = 0;
  result = strrchr(a1, 46);
  if ( result )
    ++result;
  return result;
}

