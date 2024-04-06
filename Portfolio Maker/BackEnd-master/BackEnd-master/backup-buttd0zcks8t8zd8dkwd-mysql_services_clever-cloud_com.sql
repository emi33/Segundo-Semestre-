-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: buttd0zcks8t8zd8dkwd-mysql.services.clever-cloud.com:3306
-- Generation Time: Jun 26, 2023 at 10:04 PM
-- Server version: 8.0.15-5
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `buttd0zcks8t8zd8dkwd`
--
CREATE DATABASE IF NOT EXISTS `buttd0zcks8t8zd8dkwd` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `buttd0zcks8t8zd8dkwd`;

-- --------------------------------------------------------

--
-- Table structure for table `contacto`
--

CREATE TABLE `contacto` (
  `id` bigint(20) NOT NULL,
  `personaid` bigint(20) DEFAULT NULL,
  `social` varchar(255) DEFAULT NULL,
  `user` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `contacto`
--

INSERT INTO `contacto` (`id`, `personaid`, `social`, `user`) VALUES
(52, 1, 'github', 'https://github.com/emi33/'),
(202, 1, 'youtube', 'https://www.youtube.com/channel/UCsjRyVEc5PI0uIxvd3xPbxA'),
(203, 1, 'facebook', 'facebook.com'),
(252, 2, 'github', 'https://twitter.com/');

-- --------------------------------------------------------

--
-- Table structure for table `contacto_generator`
--

CREATE TABLE `contacto_generator` (
  `next_val` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `contacto_generator`
--

INSERT INTO `contacto_generator` (`next_val`) VALUES
(351),
(1),
(1),
(1),
(1),
(1),
(1),
(1);

-- --------------------------------------------------------

--
-- Table structure for table `educacion`
--

CREATE TABLE `educacion` (
  `id` bigint(20) NOT NULL,
  `fechafin` int(11) DEFAULT NULL,
  `fechainicio` int(11) DEFAULT NULL,
  `institucion` varchar(255) DEFAULT NULL,
  `personaid` bigint(20) DEFAULT NULL,
  `titulo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `educacion`
--

INSERT INTO `educacion` (`id`, `fechafin`, `fechainicio`, `institucion`, `personaid`, `titulo`) VALUES
(302, 0, 2023, 'ITU-UNCUYO', 1, 'Desarrollo de Software'),
(303, 2016, 2011, 'Simon Bolivar', 1, 'Bachiller en Educación'),
(304, 2021, 2021, 'UTN - Academia Oracle', 1, 'Programacion Java'),
(305, 2023, 2022, 'INTI   ', 1, 'Desarrollador Full Stack'),
(354, 2023, 2019, 'Instituto de Educacion Superior', 2, 'Maestra'),
(355, 2018, 2018, 'Tonsa', 2, 'Portugues');

-- --------------------------------------------------------

--
-- Table structure for table `educacion_generator`
--

CREATE TABLE `educacion_generator` (
  `next_val` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `educacion_generator`
--

INSERT INTO `educacion_generator` (`next_val`) VALUES
(451),
(1),
(1),
(1),
(1),
(1),
(1),
(1);

-- --------------------------------------------------------

--
-- Table structure for table `experiencia`
--

CREATE TABLE `experiencia` (
  `id` bigint(20) NOT NULL,
  `cargo` varchar(255) DEFAULT NULL,
  `descripcion` varchar(255) DEFAULT NULL,
  `empresa` varchar(255) DEFAULT NULL,
  `fecha` int(11) DEFAULT NULL,
  `fechafin` int(11) DEFAULT NULL,
  `personaid` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `experiencia`
--

INSERT INTO `experiencia` (`id`, `cargo`, `descripcion`, `empresa`, `fecha`, `fechafin`, `personaid`) VALUES
(1, 'Encargado', 'Empleado de negocio de carniceria', 'Negocio Familiar', 2021, 2023, 1),
(252, 'mecanico', 'mecanico de maquinas viales', 'geovial', 2003, 2003, 1),
(302, 'Limpieza', 'Encargado en la limpieza de salas de hospital geriatrico', 'Hospital', 2020, 2020, 1),
(352, 'Vendedora', 'local de venta de quesos', 'Queseria', 1000, 3000, 2),
(402, '1111111111111', '11111111111111', '1111111', 2023, 2024, 1);

-- --------------------------------------------------------

--
-- Table structure for table `experiencia_generator`
--

CREATE TABLE `experiencia_generator` (
  `next_val` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `experiencia_generator`
--

INSERT INTO `experiencia_generator` (`next_val`) VALUES
(501),
(1),
(1),
(1),
(1),
(1),
(1),
(1);

-- --------------------------------------------------------

--
-- Table structure for table `habilidad`
--

CREATE TABLE `habilidad` (
  `id` bigint(20) NOT NULL,
  `habilidad` varchar(255) DEFAULT NULL,
  `mensual` int(11) DEFAULT NULL,
  `personaid` bigint(20) DEFAULT NULL,
  `porcentaje` int(11) DEFAULT NULL,
  `semana` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `habilidad`
--

INSERT INTO `habilidad` (`id`, `habilidad`, `mensual`, `personaid`, `porcentaje`, `semana`) VALUES
(1, 'Spring Boot', 60, 1, 65, 12),
(2, 'Angular', 40, 1, 70, 4),
(3, 'MySql', 20, 1, 40, 7),
(4, 'Java', 30, 1, 70, 8),
(202, 'Python', 80, 2, 100, 10),
(252, 'Ingles', 30, 1, 70, 12);

-- --------------------------------------------------------

--
-- Table structure for table `habilidad_generator`
--

CREATE TABLE `habilidad_generator` (
  `next_val` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `habilidad_generator`
--

INSERT INTO `habilidad_generator` (`next_val`) VALUES
(351),
(1),
(1),
(1),
(1),
(1),
(1),
(1);

-- --------------------------------------------------------

--
-- Table structure for table `persona`
--

CREATE TABLE `persona` (
  `id` bigint(20) NOT NULL,
  `acercade` varchar(4000) DEFAULT NULL,
  `apellido` varchar(255) NOT NULL,
  `banner` varchar(2000) DEFAULT NULL,
  `edad` int(11) NOT NULL,
  `email` varchar(255) DEFAULT NULL,
  `imagen` varchar(5000) DEFAULT NULL,
  `nombre` varchar(255) NOT NULL,
  `ocupacion` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `persona`
--

INSERT INTO `persona` (`id`, `acercade`, `apellido`, `banner`, `edad`, `email`, `imagen`, `nombre`, `ocupacion`) VALUES
(1, 'Soy Estudiante de Desarrollo de Software y amo aprender cosas nuevas de programación todos los días', 'Choque', 'https://firebasestorage.googleapis.com/v0/b/portfolio-maker-98538.appspot.com/o/uploads%2FBanner_1%2Fbanner_1?alt=media&token=716e4419-143e-4654-a29d-3ad03639d9da', 24, 'emiagustinchoque@gmail.com', 'https://firebasestorage.googleapis.com/v0/b/portfolio-maker-98538.appspot.com/o/uploads%2FFoto_de_perfil_1%2Ffoto_perfil_1?alt=media&token=049e3659-5338-4783-b95f-14bdb0422ddf', 'Emiliano ', 'Estudiante'),
(2, 'Ejemplo de portfolio', 'Choque', 'https://firebasestorage.googleapis.com/v0/b/portfolio-maker-98538.appspot.com/o/uploads%2FBanner_2%2Fbanner_2?alt=media&token=4126774e-fca7-4212-89d7-97f0d7a3e72b', 24, 'maria@gmail', 'https://firebasestorage.googleapis.com/v0/b/portfolio-maker-98538.appspot.com/o/uploads%2FFoto_de_perfil_2%2Ffoto_perfil_2?alt=media&token=6050e366-5d64-4452-be79-6a0f34fbea6f', 'Maria Emilia', 'Estudiante');

-- --------------------------------------------------------

--
-- Table structure for table `persona_generator`
--

CREATE TABLE `persona_generator` (
  `next_val` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `persona_generator`
--

INSERT INTO `persona_generator` (`next_val`) VALUES
(251),
(1),
(1),
(1),
(1),
(1),
(1),
(1);

-- --------------------------------------------------------

--
-- Table structure for table `proyecto`
--

CREATE TABLE `proyecto` (
  `id` bigint(20) NOT NULL,
  `desarrollo` varchar(255) DEFAULT NULL,
  `descripcion` varchar(255) DEFAULT NULL,
  `img` varchar(255) DEFAULT NULL,
  `lanzamiento` int(11) DEFAULT NULL,
  `link` varchar(255) DEFAULT NULL,
  `nombre_proyecto` varchar(255) DEFAULT NULL,
  `personaid` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `proyecto`
--

INSERT INTO `proyecto` (`id`, `desarrollo`, `descripcion`, `img`, `lanzamiento`, `link`, `nombre_proyecto`, `personaid`) VALUES
(1, '3 meses', 'es un proyecto en netbeans que simula un cajero de banco, donde se ingresa con un user y password y se puede sacar plata, retirar y ver el historial de transacciones...', 'https://firebasestorage.googleapis.com/v0/b/portfolio-maker-98538.appspot.com/o/uploads%2FFoto_proyeco_1%2Fproyecto_1?alt=media&token=b279f4b6-2396-48ac-a0ae-9b1c939f7f6d', 2021, 'no disponible', 'JAVA ATM Netbeans', 1);

-- --------------------------------------------------------

--
-- Table structure for table `proyecto_generator`
--

CREATE TABLE `proyecto_generator` (
  `next_val` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `proyecto_generator`
--

INSERT INTO `proyecto_generator` (`next_val`) VALUES
(351),
(1),
(1),
(1),
(1),
(1),
(1),
(1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `contacto`
--
ALTER TABLE `contacto`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FKtf6heanf31rp3mtn18cmmlfkd` (`personaid`);

--
-- Indexes for table `educacion`
--
ALTER TABLE `educacion`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FK2on5cafp447i8hsd4v3ms0mhg` (`personaid`);

--
-- Indexes for table `experiencia`
--
ALTER TABLE `experiencia`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FKn5vbb66vyltn0odwcx3ebc6ag` (`personaid`);

--
-- Indexes for table `habilidad`
--
ALTER TABLE `habilidad`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FKr6xw9go7y1euxsb5o703957ju` (`personaid`);

--
-- Indexes for table `persona`
--
ALTER TABLE `persona`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `proyecto`
--
ALTER TABLE `proyecto`
  ADD PRIMARY KEY (`id`),
  ADD KEY `FKah4ai7xleimw36ouy3m8p9sx9` (`personaid`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `contacto`
--
ALTER TABLE `contacto`
  ADD CONSTRAINT `FKtf6heanf31rp3mtn18cmmlfkd` FOREIGN KEY (`personaid`) REFERENCES `persona` (`id`) ON DELETE CASCADE;

--
-- Constraints for table `educacion`
--
ALTER TABLE `educacion`
  ADD CONSTRAINT `FK2on5cafp447i8hsd4v3ms0mhg` FOREIGN KEY (`personaid`) REFERENCES `persona` (`id`) ON DELETE CASCADE;

--
-- Constraints for table `experiencia`
--
ALTER TABLE `experiencia`
  ADD CONSTRAINT `FKn5vbb66vyltn0odwcx3ebc6ag` FOREIGN KEY (`personaid`) REFERENCES `persona` (`id`) ON DELETE CASCADE;

--
-- Constraints for table `habilidad`
--
ALTER TABLE `habilidad`
  ADD CONSTRAINT `FKr6xw9go7y1euxsb5o703957ju` FOREIGN KEY (`personaid`) REFERENCES `persona` (`id`) ON DELETE CASCADE;

--
-- Constraints for table `proyecto`
--
ALTER TABLE `proyecto`
  ADD CONSTRAINT `FKah4ai7xleimw36ouy3m8p9sx9` FOREIGN KEY (`personaid`) REFERENCES `persona` (`id`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
