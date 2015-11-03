<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
<xsl:output version="1.0" method="xml" encoding="windows-1251"/>

<xsl:template match="/">
<html>
	<head>
		<title>Biblioteka</title>
		<style type="text/css">
		h1 {
		color: red;
		font-family: Arial;
		}
		div.book{
		border: 1px #006600 dotted;
		margin: 10px;
		padding: 10px;
		background: #eeffee;
		}
		span.title{
		color: red;
		font-weight: bold;
		}
		dl{
		padding: 0;
		margin: 0;
		}
		dt{
		font-wieght: italic;
		color: navy;
		}
		dt.title { color: blue;}
		dt.author{ color: #1199ff; }
		dt.isbn{ color: #446688;}
		dt.pages{ color: #336611;}
		</style>
	</head>
	<body>
	<xsl:apply-templates/>
	</body>

</html>
</xsl:template>
<xsl:template match="Library">
<h1>Biblioteka</h1>
<xsl:for-each select="book">
<div class="book">
<dl>
	<dt class="title">Zaglavie:</dt>
	<dd><xsl:value-of select="book-title"/></dd>
	<dt class="author">Avtor(i):</dt>
	<xsl:for-each select="author">
	<dd>
	<xsl:value-of select="person-title"/><xsl:text> </xsl:text>
	<xsl:value-of select="name"/><xsl:text> </xsl:text>
	<xsl:value-of select="fam"/>
	</dd>
	</xsl:for-each>
	<dt class="isbn">ISBN:</dt>
	<dd>
	<xsl:value-of select="ISBN"/>
	</dd>
   <dt class="pages">Stranici:</dt>
   <dd> <xsl:value-of select="pages"/></dd>
</dl>
</div>
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>
