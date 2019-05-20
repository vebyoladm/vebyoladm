-- phpMyAdmin SQL Dump
-- version 4.2.7.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 14 Mei 2019 pada 10.19
-- Versi Server: 5.6.20
-- PHP Version: 5.5.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `mahasiswa`
--
CREATE DATABASE IF NOT EXISTS `mahasiswa` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `mahasiswa`;

-- --------------------------------------------------------

--
-- Struktur dari tabel `mahasiswatb`
--

CREATE TABLE IF NOT EXISTS `mahasiswatb` (
  `nama` varchar(30) NOT NULL,
  `npm` varchar(15) NOT NULL,
  `minggu1` varchar(6) NOT NULL,
  `minggu2` varchar(6) NOT NULL,
  `minggu3` varchar(6) NOT NULL,
  `minggu4` varchar(6) NOT NULL,
  `minggu5` varchar(6) NOT NULL,
  `minggu6` varchar(6) NOT NULL,
  `minggu7` varchar(6) NOT NULL,
  `minggu8` varchar(6) NOT NULL,
  `minggu9` varchar(6) NOT NULL,
  `minggu10` varchar(6) NOT NULL,
  `minggu11` varchar(6) NOT NULL,
  `minggu12` varchar(6) NOT NULL,
  `minggu13` varchar(6) NOT NULL,
  `minggu14` varchar(6) NOT NULL,
  `presentase` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data untuk tabel `mahasiswatb`
--

INSERT INTO `mahasiswatb` (`nama`, `npm`, `minggu1`, `minggu2`, `minggu3`, `minggu4`, `minggu5`, `minggu6`, `minggu7`, `minggu8`, `minggu9`, `minggu10`, `minggu11`, `minggu12`, `minggu13`, `minggu14`, `presentase`) VALUES
('Richard', '333', 'Hadir', 'Hadir', 'Hadir', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Hadir', 28.5714),
('Viona Eka', '111', 'Hadir', 'Hadir', 'Hadir', 'Hadir', 'Hadir', 'Tidak', 'Tidak', 'Tidak', 'Tidak', 'Hadir', 'Tidak', 'Hadir', 'Tidak', 'Hadir', 57.1429),
('Weha', '222', 'Tidak', 'Tidak', 'Tidak', 'Hadir', 'Hadir', 'Hadir', 'Tidak', 'Hadir', 'Tidak', 'Tidak', 'Tidak', 'Hadir', 'Hadir', 'Hadir', 50);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `mahasiswatb`
--
ALTER TABLE `mahasiswatb`
 ADD PRIMARY KEY (`nama`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
