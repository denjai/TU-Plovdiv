xquery version "1.0";
<Biblioteka>
{
for $a in /Library/book
where $a/price < 20.00
return
<ime>
{$a/name/text()}
{" "}
{$a/price/text()}
</ime>
}
</Biblioteka>
