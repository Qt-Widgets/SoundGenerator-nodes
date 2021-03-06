/*
 * Copyright 2019 Benoit Pelletier
 *
 * This file is part of Sound Generator.
 *
 * Sound Generator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sound Generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sound Generator.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "RandomComponent.h"
#include "Random.h"

RandomComponent::RandomComponent()
{
	m_name = "Random";
	m_inputs.push_back(ComponentInput("Amplitude", this));
	m_inputs.push_back(ComponentInput("Offset", this));

    m_inputs[0].setDefaultValue(1.0);
    m_inputs[1].setDefaultValue(0.0);
}

qreal RandomComponent::getOutput(qreal _time)
{
    qreal amplitude = m_inputs[0].getValue(_time);
    qreal offset = m_inputs[1].getValue(_time);
    return amplitude * (2 * (Random::Range(0, INT16_MAX) / static_cast<qreal>(INT16_MAX)) - 1) + offset;
}
