void __fastcall format_user_state_data(const char **a1, int a2, char *a3, int a4)
{
  if ( a2 >= 10 )
    snprintf(
      a3,
      a4,
      "{\"user\":\"%s\",\"tm\":%s,\"ifname\":\"%s\",\"fip\":\"%s\",\"bytes_in\":%s,\"bytes_out\":%s,\"pkts_in\":%s,\"pkts"
      "_out\":%s,\"peerip\":\"%s\"},",
      *a1,
      a1[1],
      a1[3],
      a1[4],
      a1[5],
      a1[6],
      a1[7],
      a1[8],
      a1[9]);
}

