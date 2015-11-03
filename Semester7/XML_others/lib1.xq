xquery version "1.0";
<Biblioteka>
{
for $a in /Library/book
return
<ime_na_kniga>
{$a/name/text()}
</ime_na_kniga>
}
</Biblioteka>
