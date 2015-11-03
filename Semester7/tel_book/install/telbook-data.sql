-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 18, 2013 at 11:08 AM
-- Server version: 5.1.54-log
-- PHP Version: 5.3.5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `telbook`
--

-- --------------------------------------------------------

--
-- Table structure for table `PERSONS_TBL`
--

CREATE TABLE IF NOT EXISTS `PERSONS_TBL` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `NAME` varchar(12) NOT NULL,
  `FAM` varchar(15) NOT NULL,
  `ADDRESS` varchar(33) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `PERSONS_TBL`
--

INSERT INTO `PERSONS_TBL` (`ID`, `NAME`, `FAM`, `ADDRESS`) VALUES
(1, 'Boian', 'Katzarsky', 'Ul. 222'),
(2, 'Velko', 'Iltchev', 'Plovdiv, 4000'),
(3, 'Ani', 'Dimitrova', 'Plovdiv, 60'),
(4, 'Bruce', 'Willis', 'Los Angeles, CA');

-- --------------------------------------------------------

--
-- Table structure for table `TELS_TBL`
--

CREATE TABLE IF NOT EXISTS `TELS_TBL` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `PID` int(11) NOT NULL,
  `TID` int(11) NOT NULL,
  `NOMER` varchar(33) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `TELS_TBL`
--

INSERT INTO `TELS_TBL` (`ID`, `PID`, `TID`, `NOMER`) VALUES
(1, 1, 1, '032 / 123 4560'),
(2, 1, 2, '0886 103 482'),
(3, 2, 3, ''),
(6, 3, 1, '02 / 456 8790');

-- --------------------------------------------------------

--
-- Table structure for table `TELTYPES_TBL`
--

CREATE TABLE IF NOT EXISTS `TELTYPES_TBL` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `TELTYPE` varchar(10) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `TELTYPES_TBL`
--

INSERT INTO `TELTYPES_TBL` (`ID`, `TELTYPE`) VALUES
(1, 'home'),
(2, 'mobile'),
(3, 'office'),
(4, 'email');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
