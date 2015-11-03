-- phpMyAdmin SQL Dump
-- version 3.5.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 14, 2013 at 11:18 AM
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

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
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `TELTYPES_TBL`
--

CREATE TABLE IF NOT EXISTS `TELTYPES_TBL` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `TELTYPE` varchar(10) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
