#!/usr/bin/perl -w
use CGI ":standard";
$total_price=0;
$total_itemi=0;
print header;
print start_html("CGI_Perl Popcorn Sales Form");
my($name,$street,$city,$payment)=(param("name"),param("street"),param("city"),param("payment"));
my($unpop,$caramel,$caramelnut,$toffeynut)=(param("unpop"),param("caramel"),param("caramelnut"),param("toffeynut"));
$total_price=3.0*$unpop+3.5*$caramel+4.5*$caramelnut+5.0*$toffeynut;
$total_items=$unpop+$caramel+$caramelnut+$toffeynut;
print h3("Customer :"),"\n";
print "$name <br />\n", "$street <br />\n", "$city <br /><br /><br />\n";
print "<b> Payment Method : </b> $payment <br /> <br />\n";
print h3("Items Ordered:"),"\n";
if($unpop>0){print "Unpopped Popcorn : $unpop <br />\n";}
if($caramel>0){print "Caramel Popcorn : $caramel <br />\n";} 
if($caramelnut>0){print "Caramel Nut Popcorn : $caramelnut <br />\n";}
if($toffeynut>0){print "Toffey Nut Popcorn : $toffeynut <br />\n";} 
print "Thanks for Ordering <br />" ;
print "<b>Your total bill is : </b> \$ $total_price <br />\n";
print end_html;
