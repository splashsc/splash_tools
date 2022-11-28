int __fastcall check_rule_num_limit(int a1, int a2, int a3, int a4, char *s, size_t maxlen)
{
  int v8; // $v0
  bool v9; // dc
  int v10; // $a2
  int result; // $v0
  const char *v12; // $v0

  v8 = get_rule_num(a3, (char)a4);
  v9 = v8 >= get_rule_num_limit(a2);
  result = 0;
  if ( v9 )
  {
    v12 = (const char *)_GET_LANG_TEXT(151, *(unsigned __int8 *)(a1 + 210102), v10);
    result = snprintf(s, maxlen, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v12);
    if ( result >= (int)maxlen )
      result = maxlen - 1;
  }
  return result;
}
// 4BE440: variable 'v10' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

