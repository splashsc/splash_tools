void __fastcall check_time_group_contain(const char *a1, const char *a2)
{
  if ( *a2 && strcmp(a2, "OFF") && !strchr(a2, 59) )
    strcmp(a1, a2);
}
// 4635C0: ignored the value written to the shadow area of the succeeding call

