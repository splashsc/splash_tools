void __fastcall format_dns_acc_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 > 0 )
    snprintf(a3, a4, "\"%s\",", *a1);
}

