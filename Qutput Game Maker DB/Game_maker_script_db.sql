USE [Game Maker]
GO
/****** Object:  Table [dbo].[Assigned]    Script Date: 5/30/2025 4:06:07 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Assigned](
	[Member Code] [int] NOT NULL,
	[Project Code] [int] NOT NULL,
	[Status] [nvarchar](50) NULL,
	[Time Line] [nvarchar](16) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Department]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Department](
	[Department Code] [int] NOT NULL,
	[Department Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Department] PRIMARY KEY CLUSTERED 
(
	[Department Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Member]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Member](
	[Member Code] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Last Name] [nvarchar](50) NULL,
	[Gemail] [varchar](320) NOT NULL,
	[Department Code] [int] NOT NULL,
 CONSTRAINT [PK_Member] PRIMARY KEY CLUSTERED 
(
	[Member Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY],
 CONSTRAINT [IX_Member] UNIQUE NONCLUSTERED 
(
	[Gemail] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Member Mobil]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Member Mobil](
	[Member Code] [int] NOT NULL,
	[Mobil] [varchar](15) NOT NULL,
 CONSTRAINT [PK_Member Mobil] UNIQUE NONCLUSTERED 
(
	[Member Code] ASC,
	[Mobil] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[NS]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[NS](
	[Platform Code] [int] NOT NULL,
 CONSTRAINT [PK_NS] PRIMARY KEY CLUSTERED 
(
	[Platform Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PC]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PC](
	[Platform Code] [int] NOT NULL,
 CONSTRAINT [PK_PC] PRIMARY KEY CLUSTERED 
(
	[Platform Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Platform]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Platform](
	[Platform Code] [int] NOT NULL,
	[Name Platform] [nvarchar](100) NOT NULL,
 CONSTRAINT [PK_Platform] PRIMARY KEY CLUSTERED 
(
	[Platform Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Project]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Project](
	[Project Code] [int] NOT NULL,
	[Project Name] [nvarchar](100) NULL,
	[Start Time] [nvarchar](16) NULL,
 CONSTRAINT [PK_Peroject] PRIMARY KEY CLUSTERED 
(
	[Project Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Project Member]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Project Member](
	[Project Code] [int] NOT NULL,
	[Member Code] [int] NOT NULL,
	[Role] [nvarchar](100) NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Project Platform]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Project Platform](
	[Project Code] [int] NOT NULL,
	[Platform Code] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Project Tool]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Project Tool](
	[Peroject Code] [int] NOT NULL,
	[Tool Code] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[PS]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PS](
	[Platform Code] [int] NOT NULL,
 CONSTRAINT [PK_PS] PRIMARY KEY CLUSTERED 
(
	[Platform Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Skill]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Skill](
	[Member Code] [int] NOT NULL,
	[Tool Code] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Task]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Task](
	[Number] [int] NOT NULL,
	[Project Code] [int] NOT NULL,
	[Member Code] [int] NULL,
	[Titel] [nvarchar](100) NOT NULL,
	[Description] [nvarchar](1000) NULL,
	[End Time Task] [nvarchar](16) NULL,
 CONSTRAINT [IX_Task] UNIQUE NONCLUSTERED 
(
	[Number] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tool]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tool](
	[Tool Code] [int] NOT NULL,
	[Tool Name] [nvarchar](100) NOT NULL,
	[Version] [varchar](11) NULL,
 CONSTRAINT [PK_Tool] PRIMARY KEY CLUSTERED 
(
	[Tool Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Xbox]    Script Date: 5/30/2025 4:06:08 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Xbox](
	[Platform Code] [int] NOT NULL,
 CONSTRAINT [PK_Xbox] PRIMARY KEY CLUSTERED 
(
	[Platform Code] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Assigned]  WITH CHECK ADD  CONSTRAINT [FK_Assigned_Member] FOREIGN KEY([Member Code])
REFERENCES [dbo].[Member] ([Member Code])
GO
ALTER TABLE [dbo].[Assigned] CHECK CONSTRAINT [FK_Assigned_Member]
GO
ALTER TABLE [dbo].[Assigned]  WITH CHECK ADD  CONSTRAINT [FK_Assigned_Peroject] FOREIGN KEY([Project Code])
REFERENCES [dbo].[Project] ([Project Code])
GO
ALTER TABLE [dbo].[Assigned] CHECK CONSTRAINT [FK_Assigned_Peroject]
GO
ALTER TABLE [dbo].[Member]  WITH CHECK ADD  CONSTRAINT [FK_Member_Department] FOREIGN KEY([Department Code])
REFERENCES [dbo].[Department] ([Department Code])
GO
ALTER TABLE [dbo].[Member] CHECK CONSTRAINT [FK_Member_Department]
GO
ALTER TABLE [dbo].[Member Mobil]  WITH CHECK ADD  CONSTRAINT [FK_Member Mobil_Member] FOREIGN KEY([Member Code])
REFERENCES [dbo].[Member] ([Member Code])
GO
ALTER TABLE [dbo].[Member Mobil] CHECK CONSTRAINT [FK_Member Mobil_Member]
GO
ALTER TABLE [dbo].[NS]  WITH CHECK ADD  CONSTRAINT [FK_NS_Platform] FOREIGN KEY([Platform Code])
REFERENCES [dbo].[Platform] ([Platform Code])
GO
ALTER TABLE [dbo].[NS] CHECK CONSTRAINT [FK_NS_Platform]
GO
ALTER TABLE [dbo].[PC]  WITH CHECK ADD  CONSTRAINT [FK_PC_Platform] FOREIGN KEY([Platform Code])
REFERENCES [dbo].[Platform] ([Platform Code])
GO
ALTER TABLE [dbo].[PC] CHECK CONSTRAINT [FK_PC_Platform]
GO
ALTER TABLE [dbo].[Project Member]  WITH CHECK ADD  CONSTRAINT [FK_Project Member_Member] FOREIGN KEY([Member Code])
REFERENCES [dbo].[Member] ([Member Code])
GO
ALTER TABLE [dbo].[Project Member] CHECK CONSTRAINT [FK_Project Member_Member]
GO
ALTER TABLE [dbo].[Project Member]  WITH CHECK ADD  CONSTRAINT [FK_Project Member_Peroject] FOREIGN KEY([Project Code])
REFERENCES [dbo].[Project] ([Project Code])
GO
ALTER TABLE [dbo].[Project Member] CHECK CONSTRAINT [FK_Project Member_Peroject]
GO
ALTER TABLE [dbo].[Project Platform]  WITH CHECK ADD  CONSTRAINT [FK_Project Platform_Peroject] FOREIGN KEY([Project Code])
REFERENCES [dbo].[Project] ([Project Code])
GO
ALTER TABLE [dbo].[Project Platform] CHECK CONSTRAINT [FK_Project Platform_Peroject]
GO
ALTER TABLE [dbo].[Project Platform]  WITH CHECK ADD  CONSTRAINT [FK_Project Platform_Platform] FOREIGN KEY([Platform Code])
REFERENCES [dbo].[Platform] ([Platform Code])
GO
ALTER TABLE [dbo].[Project Platform] CHECK CONSTRAINT [FK_Project Platform_Platform]
GO
ALTER TABLE [dbo].[Project Tool]  WITH CHECK ADD  CONSTRAINT [FK_Project Tool_Peroject] FOREIGN KEY([Peroject Code])
REFERENCES [dbo].[Project] ([Project Code])
GO
ALTER TABLE [dbo].[Project Tool] CHECK CONSTRAINT [FK_Project Tool_Peroject]
GO
ALTER TABLE [dbo].[Project Tool]  WITH CHECK ADD  CONSTRAINT [FK_Project Tool_Tool] FOREIGN KEY([Tool Code])
REFERENCES [dbo].[Tool] ([Tool Code])
GO
ALTER TABLE [dbo].[Project Tool] CHECK CONSTRAINT [FK_Project Tool_Tool]
GO
ALTER TABLE [dbo].[PS]  WITH CHECK ADD  CONSTRAINT [FK_PS_Platform] FOREIGN KEY([Platform Code])
REFERENCES [dbo].[Platform] ([Platform Code])
GO
ALTER TABLE [dbo].[PS] CHECK CONSTRAINT [FK_PS_Platform]
GO
ALTER TABLE [dbo].[Skill]  WITH CHECK ADD  CONSTRAINT [FK_Skill_Member] FOREIGN KEY([Member Code])
REFERENCES [dbo].[Member] ([Member Code])
GO
ALTER TABLE [dbo].[Skill] CHECK CONSTRAINT [FK_Skill_Member]
GO
ALTER TABLE [dbo].[Skill]  WITH CHECK ADD  CONSTRAINT [FK_Skill_Tool] FOREIGN KEY([Tool Code])
REFERENCES [dbo].[Tool] ([Tool Code])
GO
ALTER TABLE [dbo].[Skill] CHECK CONSTRAINT [FK_Skill_Tool]
GO
ALTER TABLE [dbo].[Task]  WITH CHECK ADD  CONSTRAINT [FK_Task_Member] FOREIGN KEY([Member Code])
REFERENCES [dbo].[Member] ([Member Code])
GO
ALTER TABLE [dbo].[Task] CHECK CONSTRAINT [FK_Task_Member]
GO
ALTER TABLE [dbo].[Task]  WITH CHECK ADD  CONSTRAINT [FK_Task_Project] FOREIGN KEY([Project Code])
REFERENCES [dbo].[Project] ([Project Code])
GO
ALTER TABLE [dbo].[Task] CHECK CONSTRAINT [FK_Task_Project]
GO
ALTER TABLE [dbo].[Xbox]  WITH CHECK ADD  CONSTRAINT [FK_Xbox_Platform] FOREIGN KEY([Platform Code])
REFERENCES [dbo].[Platform] ([Platform Code])
GO
ALTER TABLE [dbo].[Xbox] CHECK CONSTRAINT [FK_Xbox_Platform]
GO
